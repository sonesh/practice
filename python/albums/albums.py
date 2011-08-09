#!/usr/bin/env python

import re
import sys

# Return sortable name for artist or album title
# Leading A or The is dropped, unless the title name is just A or The
def sortableName(str):
    stripped = str.strip().lower();
    result = re.sub(r'^a\s+|the\s+', '', stripped)
    return result;

if (len(sys.argv) != 2):
    print "Usage: ./albums.py filename"
    sys.exit()

infilename  = sys.argv[1]
outfilename = infilename + ".out"

f = open(infilename, 'r')                              #Read everything into memory
text = f.read()
f.close()

#process text
text = re.sub(r'\n+','\n',text)                         #Remove successive '\n's
chunks = re.split(r'\*\*\*\s*', text)                   #Split on artist info
chunks = [item for item in chunks if item]              #Drop empties between ***'s
chunks = [re.sub(r'\n$','',x) for x in chunks]          #Remove last '\n'
chunks = [x.split('\n') for x in chunks]                #List of artist lists
chunks = [x for x in chunks if (len(x[0].strip()) > 0)] #Remove blank artists

#Create artist dictionary
# dictionary key is the sortable name of artist 
# dictionary value is list l s.t. l[0] is artist name and l[1:] are albums
catalog = {}
for artistInfo in chunks:
    artistSortableName = sortableName(artistInfo[0])
    if (artistSortableName in catalog):
        catalog[artistSortableName].extend(artistInfo[1:])  #Add albums
    else:
        catalog[artistSortableName] = artistInfo            #Add artist + albums

artistName         = None
albumName          = None
artistSortableName = None
albumSortableName  = None

#Read artist from stdin and update catalog
while (artistSortableName is None):
    print "Enter Artist Name:"
    line = sys.stdin.readline()
    artistName = line.strip()
    if (len(artistName) > 0):
            artistSortableName = sortableName(artistName)
            if (artistSortableName not in catalog):
                catalog[artistSortableName] = [artistName]

#Read album from stdin and update catalog
while (albumSortableName is None):
    print "Enter Album Name:"
    line = sys.stdin.readline()
    albumName = line.strip()
    if (len(albumName) > 0):
        albumSortableName = sortableName(albumName)
        albumSortableNames = catalog[artistSortableName][1:].sort(key =lambda x: sortableName(x))
        if (albumSortableNames is None or albumSortableName not in albumSortableNames):                        
            catalog[artistSortableName].extend([albumName])
        else:
            print "Duplicate album."
            albumSortableName = None

#Write update to catalog file
f = open(outfilename, 'w')

artists = catalog.keys()
artists.sort(key=lambda x: sortableName(x));          #Sort artists by sortable names

for artist in artists:
    f.write('*** ' + catalog[artist][0] + '\n')
    albums = catalog[artist][1:]
    albums.sort(key = lambda x: sortableName(x));     #Sort albums by sortable names
    for album in albums:
        f.write(album + '\n') 
    f.write('\n')

f.close()
