#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Abstract base class
class Shape {
public:
    virtual void draw() const = 0;
    virtual unique_ptr<Shape> clone() const = 0;
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        cout << "Drawing Circle with radius " << radius << endl;
    }

    unique_ptr<Shape> clone() const override {
        return make_unique<Circle>(*this);
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const override {
        cout << "Drawing Rectangle of " << width << "x" << height << endl;
    }

    unique_ptr<Shape> clone() const override {
        return make_unique<Rectangle>(*this);
    }
};

// Client code
void renderScene(const vector<unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->draw();
    }
}

int main() {
    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Circle>(5.0));
    shapes.push_back(make_unique<Rectangle>(4.0, 6.0));

    cout << "Original Scene:\n";
    renderScene(shapes);

    // Clone shapes
    vector<unique_ptr<Shape>> clonedShapes;
    for (const auto& shape : shapes) {
        clonedShapes.push_back(shape->clone());
    }

    cout << "\nCloned Scene:\n";
    renderScene(clonedShapes);

    return 0;
}

