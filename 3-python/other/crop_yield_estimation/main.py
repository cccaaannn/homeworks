import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

data = {'2018': [12, 15.5, 13, 14, 50], '2019': [18, 10, 16, 19, 17], '2020': [15, 14, 13, 12, 12.2]}
df = pd.DataFrame.from_dict(data, orient='index', columns=['Maize', 'Rice', 'Wheat', 'Canola', 'Tomato'])

data = [
["Maize", 2018, 12], ["Maize", 2019, 18], ["Maize", 2020, 15], 
["Rice", 2018, 15.5], ["Rice", 2019, 10], ["Rice", 2020, 14],  
["Wheat", 2018, 13], ["Wheat", 2019, 16], ["Wheat", 2020, 13], 
["Canola", 2018, 14], ["Canola", 2019, 19], ["Canola", 2020, 12], 
["Tomato", 2018, 50], ["Tomato", 2019, 17], ["Tomato", 2020, 12.2]
]

df = pd.DataFrame(data, columns=['crop', 'year', 'kg'])

sns.lineplot(data=df, x="crop", y="kg", hue="year", palette=sns.color_palette("tab10", n_colors=3)).set_title('Crop yield estimation')
plt.show()