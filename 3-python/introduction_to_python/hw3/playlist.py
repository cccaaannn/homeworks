from Song import Song

class Playlist():
    def __init__(self, name, purpose):
        self.__name = name
        self.__purpose = purpose
        self.__length = 0
        self.__song_list = []
    
    def get_song(self, i):
        return self.__song_list[i]
    
    def get_num_songs(self):
        return len(self.__song_list)
    
    def get_name(self):
        return self.__name

    def get_length(self):
        return self.__length

    def get_purpose(self):
        return self.__purpose

    def add_song(self, song):
        self.__song_list.append(song)
        self.__length += song.get_duration()

    def bubbleSort(self):
        l = len(self.__song_list)
        for i in range(l): 
            for j in range(0, l-i-1): 
                if(self.__song_list[j].get_duration() < self.__song_list[j+1].get_duration()): 
                    self.__song_list[j], self.__song_list[j+1] = self.__song_list[j+1], self.__song_list[j] 


    def sort_playlist(self):
        return self.__song_list.sort()


    def Binary_search(self, l, r, duration):
        if r >= l: 

            middle = l + (r - l)//2
            if self.__song_list[middle].get_duration() == duration: 
                return middle 

            #  continue with left 
            elif self.__song_list[middle].get_duration() < duration: 
                return self.Binary_search(l, middle-1, duration) 

            # continue with right
            else: 
                return self.Binary_search(middle+1, r, duration) 
    
        else: 
            return -1


    def __repr__(self):
        __songs = ""
        for song in self.__song_list:
            __songs += str(song)
        return __songs
