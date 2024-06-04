package main

import "fmt"

type IObserver interface {
	Update(message string)
}

type IObserverable interface {
	AddObserver(o IObserver)
	RemoveObserver(o IObserver)
	Notify()
}

type Person struct {
	name string
}

func (p Person) Update(message string) { fmt.Println(p.name, "is notified") }

type Ticket struct {
	cost      int
	observers []IObserver
}

func (t *Ticket) SetCost(cost int) {
	t.cost = cost
	t.Notify()
}

func (t *Ticket) AddObserver(o IObserver) {
	if t.observers == nil {
		t.observers = make([]IObserver, 0)
	}
	t.observers = append(t.observers, o)
}

func (t *Ticket) RemoveObserver(o IObserver) {
	for i, obs := range t.observers {
		if obs == o {
			t.observers = append(t.observers[:i], t.observers[i+1:]...)
			fmt.Printf("%T is removed from %T\n", o, t)
			return
		}
	}
}

func (t *Ticket) Notify() {
	for _, v := range t.observers {
		v.Update("")
	}
}

func main() {
	ticket := Ticket{}
	person := Person{name: "Mike"}

	ticket.AddObserver(person)
	ticket.SetCost(4)

	ticket.RemoveObserver(person)
	ticket.SetCost(5)
}
