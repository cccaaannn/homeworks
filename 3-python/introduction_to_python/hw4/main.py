import numpy as np
import matplotlib.pyplot as plt
import numpy.polynomial.polynomial as poly


# -----q1-----
data = np.loadtxt("data.txt")
sales = data * 90 / 100

print("Projected Sales:", sales)
print("Projected sales over mean:", sales[sales > sales.mean()])
print("Index(es) of the books with maximum projected sales:", np.where(sales==sales.max())[0])

indexes = np.arange(1,sales.shape[0]+1 , 1)

c = poly.polyfit(indexes, sales, 2)
f = poly.polyval(indexes, c)

plt.scatter(indexes, sales, c='tab:red', label='Projected Sales')
plt.plot(indexes, f, label='Best Fit - Projected Sales')

plt.legend(loc=2)
plt.show()
# ------------


# -----q2 first part-----
top50_info = np.loadtxt("top50info.txt", dtype=np.str, delimiter='\t', skiprows=1)
top50 = np.loadtxt("top50.txt", delimiter='\t', skiprows=1)

# array_edm = np.concatenate((top50_info[np.where(top50_info=="edm")[0]], top50[np.where(top50_info=="edm")[0]]),axis=1)
array_edm = top50[np.where(top50_info=="edm")[0]]
edm_names = top50_info[np.where(top50_info=="edm")[0]][:,0]

fig1, axs = plt.subplots(2)
axs[0].pie(array_edm[:,4], labels=edm_names)
axs[0].title.set_text("Popularity of Electronic Dance Music (edm)")

axs[1].hist(top50[:,0],  bins=4)
axs[1].title.set_text("Frequencies of Beats per Minute (All Songs) in 4 Bins")

plt.show()
# ---------------


# -----q2 second part-----
ed = top50[np.where(top50_info=="Ed Sheeran")[0]]
billie = top50[np.where(top50_info=="Billie Eilish")[0]]
ed_billie = np.concatenate((ed, billie),axis=0)

plt.plot(ed_billie[:,0], ed_billie[:,4], "-o", c='tab:red',linestyle='dashed', label='Popularity')
plt.plot(ed_billie[:,0], ed_billie[:,1], "-o", c='tab:blue',linestyle='dashed', label='Danceability')
plt.xlabel('Beats per Minute')
plt.legend()

plt.show()
# ---------------