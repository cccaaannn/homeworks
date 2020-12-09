
class Doctor():
    def __init__(self, dname, title):
        self.__dname = dname
        self.__title = title
    
    def set_dname(self, dname):
        self.__dname = dname

    def get_dname(self):
        return self.__dname

    def set_title(self, title):
        self.__title = title
    
    def get_title(self):
        return self.__title
    
    def __eq__(self, other):
        if(self.__dname == other.get_dname() and self.get_title() == other.get_title()):
            return True
        else:
            return False
    
    def __lt__(self, other):
        if(self.get_title() < other.get_title()):
            return True
        elif(self.get_title() == other.get_title()):
            if(self.get_dname() < other.get_dname()):
                return True
            else:
                 return False
        else:
            return False

    def repr__(self):
        print("{} - {}".format(self.get_title(), self.get_dname()))
    



class Private(Doctor):
    def __init__(self, dname, title, patients, treatmentFee):
        super().__init__(dname, title)
        self.__patients = float(patients)
        self.__treatmentFee = float(treatmentFee)

    def calculate_payment(self):
        return self.__patients * self.__treatmentFee

    def repr__(self):
        print("{} - {}: {}".format(self.get_title(), self.get_dname(), self.calculate_payment()))




class State(Doctor):
    __baseBonus = 5000
    def __init__(self, dname, title, salary):
        super().__init__(dname, title)
        self.__salary = float(salary)
        
    def calculate_payment(self):
        if(self.get_title() == "Professor"):
            return self.__salary + (1.25 * State.__baseBonus)
        elif(self.get_title() == "Associate Professor"):
            return self.__salary + State.__baseBonus
        elif(self.get_title() == "Assistant Professor" or self.get_title() == "Specialist"):
            return self.__salary + (0.75 * State.__baseBonus)

    def repr__(self):
        print("{} - {}: {}".format(self.get_title(), self.get_dname(), self.calculate_payment()))



file = open("doctor_data.txt")
text = file.read()
file.close()

splitted_texts = text.split("\n")
splitted_texts = [doctor.split(";") for doctor in splitted_texts]



doctors = []
for splitted_text in splitted_texts:

    if(len(splitted_text) == 3):
        new_doctor = State(splitted_text[0],splitted_text[1],splitted_text[2])
    if(len(splitted_text) == 4):
        new_doctor = Private(splitted_text[0],splitted_text[1],splitted_text[2],splitted_text[3])
    
    if(new_doctor not in doctors):
        doctors.append(new_doctor)
    else:
        new_doctor.repr__()
        print("not added, duplicate!")

doctors = sorted(doctors)
for doctor in doctors:
    doctor.repr__()




