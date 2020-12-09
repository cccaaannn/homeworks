# -*- coding: utf-8 -*-
"""
@author: user
"""

class Location(object):
    
    def __init__(self,city,name):
        self.__location_name = name
        self.__city = city
    
    def __lt__(self,other):
        if(self.__city < other.get_city()):
            return True
        elif(self.__city == other.get_city() and self.__location_name < str(other).split(" - ")[0]): #hocam başka fonksiyon tanımlama demişsiniz
            return True
        else:
            return False
        
    def __eq__(self,other):
        if(self.__city == other.get_city() and self.__location_name == str(other).split(" - ")[0]): #hocam başka fonksiyon tanımlama demişsiniz
            return True  
        else:
            return False
        
    def get_city(self):
        return self.__city

    # def get_location_name(self):
    #     return self.__location_name

    def __repr__(self):
        return '{} - {}'.format(self.__location_name,self.__city)