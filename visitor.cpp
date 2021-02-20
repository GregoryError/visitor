#include "visitor.h"
#include <iostream>

Item::Item(const char* n) {
    name = n;
}

std::string Facility::getName() {
    return name;
}


Room::Room(const char* n) {
    name = n;
}

void Room::add(Facility *f) {
    childs.push_back(f);
}

void Room::remove(Facility *f) {
    auto f_it = std::find(childs.begin(), childs.end(), f);
    if (f_it != childs.end())
        childs.erase(f_it);
}

Facility* Room::childAt(const int node) {
    return childs[node];
}

std::string Room::getItems() {
    for (const auto& i : childs)
        items_str += i->getName() + '\n';
    return items_str;
}


void visitor::addData(const std::string s) {
    inventory_str += s + '\n';
}

void visitor::Show() {
    std::cout << inventory_str << '\n';
}


void visitor::VisitRoom(Room *obj) {
    addData("\nRoom: \"" + obj->getName() + "\"\n");
}

void visitor::VisitItem(Item *obj) {
    addData(obj->getName());
}

void Room::Accept(visitor *v) {
     v->VisitRoom(this);
    for (const auto& i : childs)
        i->Accept(v);
}

void Item::Accept(visitor *v) {
    v->VisitItem(this);
}



visitor::visitor() {

}

