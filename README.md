# Hotel_Booking_System

A simple console-based Hotel Management System implemented in C++ using Object-Oriented Programming (OOP) principles. This project simulates basic hotel operations such as managing rooms, customers, bookings, and billing.

It is designed for learning purposes and demonstrates how real-world hotel booking systems can be modeled using classes, objects, and STL containers.


📌 Features

Add new rooms with room type and price

Register new customers

Book available rooms for specific number of days

Automatically update room availability after booking

Display all rooms, customers, and booking details

Search customer using customer ID

Generate bill using booking ID and customer ID

Calculate total booking cost based on room price and number of days


🧱 Project Structure

The system consists of the following main classes:

1. Room Class
Stores room number, type, price, and availability
Provides functions to display and update room information

2. Customer Class
Stores customer ID, name, and phone number
Provides functions to display customer details

3. Booking Class
Stores booking ID, customer ID, room number, number of days, and total bill
Automatically calculates total bill

4. Hotel Class
Acts as the main management system
Stores lists of rooms, customers, and bookings using STL vectors
Handles room booking, checkout, display, search, and bill generation


-> Technologies Used
C++
Object-Oriented Programming (OOP)
STL Vector
Console I/O
