#read file
with open("clean_data.csv", encoding="utf8") as file:
	data = file.read().split("\n")

header = data[0]
students = data[1:]

total_student = len(students)

#split header
header = header.split(",")
subjects = header[5:]

#split each student in list
for i in range(len(students)):
	students[i] = students[i].split(",")

#remove last student
students.pop()

#get number of student per age group
#17 18 19 ... 26 >=27
num_of_student_per_age_group = [0,0,0,0,0,0,0,0,0,0,0]
average_of_student_per_age_group = [0,0,0,0,0,0,0,0,0,0,0]

for s in students:
	age = 2020 - int(s[4])
	if age >= 27:
		age = 27
	num_of_student_per_age_group[age - 17] += 1

	sum_score = 0 # Sum score
	count_score = 0 # Number of subject
	for i in range(11):
		if s[i+5] != "-1":
			count_score += 1
			sum_score += float(s[i+5])

	average = sum_score/count_score
	average_of_student_per_age_group[age-17] += average

for i in range(len(average_of_student_per_age_group)):
	average_of_student_per_age_group[i] = average_of_student_per_age_group[i]/num_of_student_per_age_group[i]

for i in range(len(average_of_student_per_age_group)):
	average_of_student_per_age_group[i] = average_of_student_per_age_group[i] * 7000

print(num_of_student_per_age_group)
print(average_of_student_per_age_group)

#plot barchart
import matplotlib.pyplot as plt
import numpy as np

age_label = [17,18,19,20,21,22,23,24,25,26,">26"]
x = np.arange(11)
y = np.arange(11)

fig, axis = plt.subplots()

plt.bar(x, num_of_student_per_age_group)
plt.plot(x, average_of_student_per_age_group, color='red', marker='o')

#change horizontal category name
plt.xticks(x, age_label)

#set limit to vertical axis
axis.set_ylim(0, 70000)

#label and title
plt.ylabel('Số học sinh')
plt.xlabel("Tuổi")
plt.title('Điểm trung bình theo độ tuổi')

#right side ticks
ax2 = axis.twinx()
ax2.tick_params('y', colors='r')
ax2.set_ylim(0,10)
ax2.set_ylabel("Điểm trung bình")

rects = axis.patches
labels = [2, 66327, 4463, 1396, 767, 384, 300, 223, 177, 109, 296]
# Make some labels.
for rect, label in zip(rects, labels):
    height = rect.get_height()
    axis.text(rect.get_x() + rect.get_width() / 2, height, label, ha='center', va='bottom')

plt.show()