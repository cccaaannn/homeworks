import numpy as np


# load districts
districts = np.loadtxt("ilceler.txt", dtype='str', encoding="utf8")

# load votes
votes = np.loadtxt("votes.txt", dtype='int', skiprows=1)

# set candidate names
candidate_names = np.array(["Muharrem I.", "temel", "Meral A.", "Recep E.", "perincek", "Demirtas"])

# -------------------------------------------------------------------------------------

# calculate district vote usage %
district_vote_usage = votes[:,1] / votes[:,0] * 100

# print district vote usage %
print("\ndistrict vote usage %")
for district, vote in zip(districts, district_vote_usage):
    print("{:20s}  %{:0.5f}".format(district, vote))

# -------------------------------------------------------------------------------------

# calculate total vote usage %
total_vote_usage = sum(votes[:,1]) / sum(votes[:,0]) * 100

# print total vote usage %
print("\ntotal vote usage %")
print("total vote usage %", total_vote_usage)

# -------------------------------------------------------------------------------------

total_vote_percentages = np.zeros(6)
for i in range(6):
    total_vote_percentages[i] = sum(votes[:,i+2]) / sum(votes[:,1]) * 100

# print total vote %
print("\ntotal vote %")
print(candidate_names)
print(total_vote_percentages)

# -------------------------------------------------------------------------------------

# calculate individual vote %
individual_vote_percentages = np.zeros([votes.shape[0],6])
for i in range(len(votes)):
    individual_vote_percentages[i] = (votes[i][2:8] / votes[i][1] * 100)

# save individual votes %
np.savetxt("vote_percentages.txt", individual_vote_percentages)

# print individual vote %
print("\nindividual vote %")
print(20*" ", candidate_names)
for district, individual_vote_percentage in zip(districts, individual_vote_percentages):
    print("{:20s} {}".format(district,individual_vote_percentage))

# -------------------------------------------------------------------------------------

# find personal to 10s
print("\ncandidates personal top 10s")
for i in range(6):
    candidate = individual_vote_percentages[:,i]
    sorting_indexes = candidate.argsort()
    candidate = candidate[sorting_indexes][::-1]
    candidate_districts = districts[sorting_indexes][::-1]

    print(candidate_names[i])
    for j in range(10):
        print("{}:%{:0.0f}".format(candidate_districts[j],candidate[j]), end=", ")
    print("")


