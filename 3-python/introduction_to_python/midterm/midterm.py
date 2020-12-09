def read_student(file):
    departments = {}
    while True: 
        
        line = file.readline().split()[-3:]
        if not line: 
            break
        else:
            if line[1] in departments:
                departments[line[1]].append((line[0], float(line[2])))
            else:
                departments.update({line[1]:[(line[0], float(line[2]))]})
    return departments


def find_average(departments, department):
    students = departments[department]
    gpa_sum = 0
    for student in students:
        gpa_sum += student[1]
    gpa_avg = gpa_sum/len(students)
    return gpa_avg

def rem_stu(departments, surname):
    for department in departments:
        students = departments[department]
        for student in students:
            if(student[0] == surname):
                students.remove(student)
        departments.update({department:students})
    return departments

def print_stu(departments):
    for department in departments:
        print("Department: ", department)
        for student in departments[department]:
            print("\t", student)


file = open("student.txt", 'r') 
departments = read_student(file)
file.close()

avg = find_average(departments, "IR")
print(avg)

print_stu(departments)
while True:
    surname = input("Enter surname of the student to be removed (quit will stop):")

    if(surname == "quit"):
        break
    
    departments = rem_stu(departments, surname)

print_stu(departments)