🚗 Car Rental System

Welcome to the Car Rental System, a simple yet effective platform for managing car rentals. This project is built in C, showcasing a structured and modular approach to application development.

📋 Features

User Registration and Login 🔒

Register new users with unique credentials.

Secure login functionality for existing users.

Car Management 🚘

View the list of available cars with details such as brand, model, and rental price.

Rent a car of your choice (availability checked).

Return previously rented cars.

Dynamic Data Structures 📂

Cars and users are stored as linked lists for efficient memory usage and dynamic updates.

User Menu 🛠

Access a clean and interactive menu after login to perform actions like renting, returning cars, and viewing car details.

🏗️ Project Structure

Code Overview:

Main Program Logic:

Handles user input, navigation, and menu-driven operations.
Functions:

initializeCars() - Pre-populates car data into the system.

registerUser() - Registers new users.

loginUser() - Authenticates users and provides access to rental operations.

displayCars() - Lists all available cars for rent.

rentCar() - Allows users to rent a car by entering its number.

returnCar() - Facilitates returning a rented car.

logoutUser() - Logs the user out.

exitProgram() - Cleans up dynamically allocated memory and exits.
