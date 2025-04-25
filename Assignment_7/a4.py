'''4. Create a class "Employee" with attributes name and salary. Implement overloaded operators + 
and - to combine and compare employees based on their salaries'''

class Employee:
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary

    def __add__(self, other):
        # Combine salaries of two employees.
        return self.salary + other.salary

    def __sub__(self, other):
        # Compare salaries of two employees
        return self.salary - other.salary

    def __repr__(self):
        return f"Employee({self.name}, {self.salary})"

# Example Usage
e1 = Employee("Alice", 5000)
e2 = Employee("Bob", 3000)

total_salary = e1 + e2  # Adding salaries
salary_difference = e1 - e2  # Subtracting salaries

print(f"Total Salary: {total_salary}")
print(f"Salary Difference: {salary_difference}")