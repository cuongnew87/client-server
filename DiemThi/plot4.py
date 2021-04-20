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

name = []
name_count = []

for s in students:
	s_name = s[1].split(" ")
	lastname = s_name[0]
	if lastname not in name:
		name.append(lastname)
		name_count.append(0)
		name_count[name.index(lastname)] += 1
	else:
		name_count[name.index(lastname)] += 1

counted_max_num = []
sorted_index =  []

for i in range(len(name)):
	max_number = 0
	for j in range(len(name)):
		if name_count[j] > max_number and name_count[j] not in counted_max_num:
			n=max_number = name_count[j]

	counted_max_num.append(max_number)


for max_num in counted_max_num:
	for i in range(len(name)):
		if name_count[i] == max_num and i not in sorted_index:
			sorted_index.append(i)

name_sorted = []
name_count_sorted = []

for index in sorted_index:
	name_sorted.append(name[index])
	name_count_sorted.append(name_count[index])

#plot barchart
import matplotlib.pyplot as plt
import numpy as np

num = 20

x = np.arange(20)
y = np.arange(20)

fig, axis = plt.subplots()

plt.bar(x, name_count_sorted[0:num])

#change horizontal category name
plt.xticks(x, name_sorted[0:num])

#set limit to vertical axis
axis.set_ylim(0, 30000)

#label and title
axis.set_ylabel('Số học sinh')

rects = axis.patches
labels = name_count_sorted[0:num]
# Make some labels.
for rect, label in zip(rects, labels):
    height = rect.get_height()
    axis.text(rect.get_x() + rect.get_width() / 2, height, label, ha='center', va='bottom')

plt.title(str(num) +' họ phổ biến nhất')

plt.show()