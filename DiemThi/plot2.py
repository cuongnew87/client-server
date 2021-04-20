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

num_of_exam_taken = [0,0,0,0,0,0,0,0,0,0,0,0]
average = [0,0,0,0,0,0,0,0,0,0,0,0]
#number of student who took 0,1,2,3,... subjects
for s in students:
	count = 0
	total = 0
	for i in range(11):
		if s[i+5] != "-1":
			total += float(s[i+5])
			count += 1

	num_of_exam_taken[count] += 1
	average[count] += total/count

for i in range(12):
	if num_of_exam_taken[i] != 0:
		average[i] = round(average[i]/num_of_exam_taken[i], 2)

print(num_of_exam_taken)
print(average)

#plot barchart
import matplotlib.pyplot as plt
import numpy as np

x = np.arange(12)
y = np.arange(12)

fig, axis = plt.subplots()

plt.bar(x, average)

#change horizontal category name
plt.xticks(x, y)

#set limit to vertical axis
axis.set_ylim(0, 10)

#label and title
plt.ylabel('Điểm trung bình')
plt.title('Số học sinh không thi hoặc không đăng ký')

rects = axis.patches
labels = average
# Make some labels.
for rect, label in zip(rects, labels):
    height = rect.get_height()
    axis.text(rect.get_x() + rect.get_width() / 2, height, label, ha='center', va='bottom')

plt.show()