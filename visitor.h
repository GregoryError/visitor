#ifndef VISITOR_H
#define VISITOR_H

#include <vector>
#include <string>

class Facility
{
protected:
    std::string name;
public:
    std::string getName();
    virtual void add(Facility* f) {}
    virtual void remove(Facility* f) {}
    virtual Facility* childAt(const int node) { return nullptr; }
    virtual void Accept(class visitor* v) = 0;
    virtual ~Facility() {}
};

// Leaf
class Item : public Facility
{
public:
    Item(const char* n);
    void Accept(class visitor *v) override;
};

// Composed object
class Room : public Facility
{
private:
    std::vector<Facility*> childs;
    std::string items_str;
public:
    Room(const char* n);
    void add(Facility *f) override;
    void remove(Facility *f) override;
    Facility * childAt(const int node) override;
    std::string getItems();
    void Accept(class visitor *v) override;
};

class visitor
{
private:
    std::string inventory_str;
public:
    visitor();
    void addData(const std::string s);
    virtual void VisitRoom(Room* obj);
    virtual void VisitItem(Item* obj);
    void Show();
    virtual ~visitor() {}
};

#endif // VISITOR_H


















