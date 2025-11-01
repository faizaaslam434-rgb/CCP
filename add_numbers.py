#!/usr/bin/env python3
"""
Simple program to add two numbers
"""

def add_numbers(num1, num2):
    """Add two numbers and return the result"""
    return num1 + num2

if __name__ == "__main__":
    # Get input from user
    try:
        number1 = float(input("Enter first number: "))
        number2 = float(input("Enter second number: "))
        
        result = add_numbers(number1, number2)
        
        print(f"\nResult: {number1} + {number2} = {result}")
    
    except ValueError:
        print("Error: Please enter valid numbers")
    except KeyboardInterrupt:
        print("\n\nProgram interrupted by user")
