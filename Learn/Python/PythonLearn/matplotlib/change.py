import matplotlib.pyplot as plt

fig, ax = plt.subplots()
fruits = ['apple', 'blueberry', 'pear', 'orange']
counts = [40, 100, 15, 55]
bar_labels = ['red', 'blue', 'green', 'orange']
bar_colors = ['tab:red', 'tab:blue', 'tab:green', 'tab:orange']

ax.bar(fruits, counts, label=bar_labels, color=bar_colors)

ax.set_ylabel('fruit supply')
ax.set_title('Fruit supply by kind and color')
ax.legend(title='Fruit color')

plt.show()
