import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

import java.lang.String;

import java.util.Collection;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

public class AlbumCollection {
  
  //Return a string that can be used as key for sorting
  //Removes leading A or The
  //But if the name is just A or The, keeps it
  private static String getSortableName(String name) {
    String lowerCase = name.trim().toLowerCase();
    if (lowerCase.startsWith("a "))
      return lowerCase.substring(2).trim();
    else if (lowerCase.startsWith("the "))
      return lowerCase.substring(4).trim();
    else 
      return lowerCase;
  }


  public static void main (String[] args) {

    if (args.length < 1) {
      System.out.println("Usage: java AlbumCollection fileName");
      System.exit(-1);
    }

    String inFileName = args[0];
    Map<String, Artist> artists = new TreeMap<String, Artist>();

    Artist artist      = null;
    String artistName  = null;
    String artistKey   = null;
    String albumName   = null;
    String albumKey    = null;
    String line        = null;

    BufferedReader input  = null;
    BufferedWriter output = null;

    //Read initial catalog from file
    try {
      try {
        input = new BufferedReader(new FileReader(inFileName));
        
        while ( (line = input.readLine()) != null) {
          if ( (artist == null) && line.startsWith("***") ) {
            artistName = line.substring(3);            //Ignore *'s
            artistKey = getSortableName(artistName);
            if (artistKey.length() == 0)               
              continue;                                //Skip blank artist
            if (artists.containsKey(artistKey))
              artist = artists.get(artistKey);
            else {
              artist = new Artist(artistName);
              artists.put(artistKey, artist);
            }
          } else if (line.trim().length() ==  0) 
            artist = null;                            //Blank line => done
          else if (artist != null) {
            albumName = line;                 
            albumKey  = getSortableName(line);
            artist.addAlbum(albumKey, albumName);    //Add artist's album 
          }
          else
            ; //Ignore input line
        }
      }
      finally {
        if (input != null)
          input.close();
      }
    }
    catch (IOException ex) {
      ex.printStackTrace();
      System.exit(-1);
    } 

    //Get input from user
    artist     = null;
    artistName = null;
    artistKey  = null;
    albumName  = null;
    albumKey   = null;
    line       = null;

    try {
      try {
        input = new BufferedReader(new InputStreamReader(System.in));
        output = new BufferedWriter(new OutputStreamWriter(System.out));
        output.write("Enter album info\n");
        output.flush();
        //Get Artist name
        while (artist == null) {
          output.write("Enter Artist name:\n");
          output.flush();
          if ( (line = input.readLine()) != null && line.trim().length() != 0 ) {
            artistName = line.trim();
            artistKey  = getSortableName(artistName);
            if (artists.containsKey(artistKey))
              artist = artists.get(artistKey);     //Artist already exists
            else {
              artist = new Artist(artistName);
              artists.put(artistKey, artist);      
            }
          }
        }
        
        //Get Album name
        while (albumName == null) {
          output.write("Enter Album name:\n");
          output.flush();
          if ( (line = input.readLine()) != null && line.trim().length() != 0) {
            albumName = line.trim();
            albumKey  = getSortableName(albumName);
            if (!artist.addAlbum(albumKey, albumName)) {
              output.write("Duplicate Album. ");
              output.flush();
              albumName = null;
              albumKey  = null;
            }
          }
        }
      }
      finally {
        if (input != null)
          input.close();
        if (output != null)
          output.close();
      }
    }
    catch (IOException ex) {
      ex.printStackTrace();
      System.exit(-1);
    }
    
    //Write back whole album catalog
    String outFileName = inFileName + ".out";
    try{
      try {
        output = new BufferedWriter(new FileWriter(outFileName));
        Collection artistValues = artists.values();
        Iterator it = artistValues.iterator();
        while (it.hasNext()) {
          artist = (Artist) it.next();
          output.write(artist.toString());
        }
      }
      finally {
        if (output != null)
          output.close();
      }
    }
    catch (IOException ex) {
      ex.printStackTrace();
      System.exit(-1);
    }

    System.exit(0);
  }

}

