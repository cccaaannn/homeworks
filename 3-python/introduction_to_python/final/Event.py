# -*- coding: utf-8 -*-
"""
@author: user
"""
from Location import Location


class Event(object):
    
    __ticketFee = 25

    def __init__(self, ename, tprice, date, city, loc_name):
        self.__event_name = ename
        self.__price = int(tprice)
        self.__date = date
        self.__location = Location(city, loc_name)
        self.__active = True

    def get_month(self):
        return int(self.__date.split("/")[1])

    def get_location(self):
        return self.__location

    def calculate_ticket_price(self):
        if(self.__location.get_city() == "Istanbul"):
            return self.__price + Event.__ticketFee
        else:
            return self.__price + (Event.__ticketFee * 0.75)

    def __lt__(self, other):
        if(self.__location < other.get_location()):
            return True
        elif(self.__location == other.get_location() and self.calculate_ticket_price() < other.calculate_ticket_price()):
            return True
        else:
            return False
        
    def set_active(self):
        self.__active = not self.__active
    
    def is_active(self):
        return self.__active
        
    def __repr__(self):
        s = ''
        if not self.is_active():
            s = '**CANCELLED** '
        return s + '{} {} ({}TL): {}\n'.format(self.__event_name, self.__date,self.calculate_ticket_price(),self.__location)
        
        


