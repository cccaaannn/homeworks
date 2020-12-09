# -*- coding: utf-8 -*-
"""
Created on Tue May 19 11:22:35 2020

@author: user
"""


from Event import *

#open file biletix.txt
file = open("biletix.txt",'r')

#empty list to store Events from file
events = []

#read the data from the file, and using the data from the file, 
#create Events and add to the empty list defined above
file_contents = file.read()
file_contents = file_contents.split("\n")
file_contents = [file_content.split(";") for file_content in file_contents]

for file_content in file_contents:
    events.append(Event(file_content[0],file_content[-1],file_content[1],file_content[3],file_content[2]))


#sort the list of Events
events = sorted(events)

#display the list of events
print(events)

#cancel/deactivate all events before October
for event in events:
    if(event.get_month() < 10):
        event.set_active()

#print the updated list of events
print(events)

#input a city and location name from the user
city = input('Enter city to search: ')
vname = input('Enter name of location to search: ')

#Using the data input by the user, create a Location, 
loc = Location(city, vname)
#display all Events at the given Location. 
#If no events at the given Location, display appropriate message

events_on_location = []
for event in events:
    if(event.get_location() == loc and event.is_active()):
        events_on_location.append(event)


if(not events_on_location):
    print("No Events Found")
else:
    print("Active Events at : {}".format(loc))
    print(*events_on_location)





