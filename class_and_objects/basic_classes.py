import numpy as np
import time

class Vehicle:
    def __init__(self, wheels, make_year=2000):
        self.wheels = wheels
        self.transmission_type = "automatic"
        self.make_year = make_year

    def print_name(self):
        print(self.wheels)


class Truck(Vehicle):
    def __init__(self, wheels, make_year, utility, capacity):
        super().__init__(wheels, make_year)
        self.utility = utility
        self.capacity = capacity

class Point:
    points = []
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
        self.points.append(self)

    def __add__(self, p1):
        return Point(self.x + p1.x, self.y + p1.y, self.z + p1.z)

    def __sub__(self, p1):
        return Point(self.x - p1.x, self.y - p1.y, self.z - p1.z)

    def __str__(self):
        return "{" + str(self.x) + ", " + str(self.y) + ", " + str(self.z) + "}" 

    def print_pt(self):
        print("The point x, y, z are:", self.x, self.y, self.z)

    @classmethod
    def no_points(cls):
        print("Number of points in class is: ", len(cls.points))

    @staticmethod
    def demo_method(n):
        for i in range(n):
            print("Point class static method")


if __name__ == "__main__":
    v1 = Vehicle(4)
    t1 = Truck(8, 2021, "severe", 10)
    print(t1.wheels)
    pt1 = Point(1,2,3)
    pt2 = Point(10,1,1)
    pt1 = pt1 + pt2

    pt1.print_pt()
    print(pt2)
    print(Point.points[0])
    Point.no_points()
    Point.demo_method(2)

    print("Main",6)