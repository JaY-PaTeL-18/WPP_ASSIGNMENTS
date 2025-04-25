class Converter:
    conversion_factors = {
        "inche": 0.0254,
        "feet": 0.3048,
        "yard": 0.9144,
        "mile": 1609.34,
        "kilometer": 1000,
        "meter": 1,
        "centimeter": 0.01,
        "millimeter": 0.001
    }
    def __init__(self,length,unit):
        self.unit=unit.lower()
        if unit not in self.conversion_factors:
            print("Invalid Input!")
        self.length_in_meters= length * self.conversion_factors[unit]

    def convert_the_unit(self,targeted_unit):
        self.targeted_unit=targeted_unit
        if targeted_unit not in self.conversion_factors:
            print("Invalid Input!")
        return self.length_in_meters/self.conversion_factors[targeted_unit]

    

length=int(input("Enter the length : "))
Unit=input("Enter the unit of the length : ")
unit2=input("Enter the unit you want to convert in : ")
k=Converter(length,Unit)
print(f"Length in {unit2} is ",k.convert_the_unit(unit2))