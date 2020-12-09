from playlist import Playlist
from Song import Song
import os


def create_playlist(filename, playlist, type):
    with open(filename,'r') as file:
        content = file.read()
    
    content = content.split("\n")
    content.remove(content[-1])
    content = [item.split("\t") for item in content]

    for i in content:
        if(i[-1] == "workout"):
            new_song = Song(i[0], i[1], i[2])
            playlist.add_song(new_song)

    playlist.bubbleSort()
    print("Bubble sorted playlist: {} {} {} minutes".format(playlist.get_name(), type, playlist.get_length()//60))
    print(playlist)

    duration = int(input("Enter duration of song: "))
    song_index = playlist.Binary_search(0, playlist.get_num_songs()-1, duration)
    if(song_index == -1):
        print("no such song\n")
    else:
        found_song = playlist.get_song(song_index)
        print("Song with duration {} {}".format(duration, found_song))

    playlist.sort_playlist()
    print("Default sorted playlist: {} {} {} minutes".format(playlist.get_name(), playlist.get_purpose(), playlist.get_length()//60))
    print(playlist)


April2020GymHits = Playlist("April2020GymHits", "workout")

create_playlist("April2020GymHits.txt", April2020GymHits, "workout")
