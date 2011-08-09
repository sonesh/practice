import java.lang.String;
import java.lang.StringBuilder;

import java.util.Collection;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

public class Artist {

  private String fullName;
  private Map<String, String> albums;

  public Artist (String fullName) {
    this.fullName = fullName.trim();
    albums = new TreeMap<String, String>();
  }
  
  public String getFullName() {
    return fullName;
  }

  //Return false if key already inserted
  public boolean addAlbum(String albumKey, String albumName) {
    if (albums.containsKey(albumKey))
        return false;
    else {
      albums.put(albumKey, albumName);
      return true;
    }
  }

  @Override public String toString() {
    StringBuilder result = new StringBuilder();
    //String newLine = System.getProperty("line.separator");
    String newLine = "\n";
    
    result.append("*** ");
    result.append(fullName);
    result.append(newLine);

    String albumTitle = null;
    Collection albumTitles = albums.values();
    Iterator it = albumTitles.iterator();
    while (it.hasNext()) {
      albumTitle = (String) it.next();
      result.append(albumTitle);
      result.append(newLine);
    }
    result.append(newLine);
    return result.toString();
  }

}
