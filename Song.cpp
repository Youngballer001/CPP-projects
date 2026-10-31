#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Song class
class Song
{
private:
    string title;
    int duration; // Duration in seconds

public:
    // Default constructor
    Song()
    {
        title = "";
        duration = 0;
    }

    // Parameterized constructor
    Song(string t, int d)
    {
        title = t;
        duration = d;
    }

    // Getter methods
    string getTitle() const
    {
        return title;
    }

    int getDuration() const
    {
        return duration;
    }
};

// Playlist class
class Playlist
{
private:
    Song songs[10];
    int songCount;

public:
    Playlist()
    {
        songCount = 0;
    }

    // Add a song to the playlist
    void addSong(Song s)
    {
        if (songCount < 10)
        {
            songs[songCount] = s;
            songCount++;
        }
        else
        {
            cout << "Playlist is full! Cannot add more songs.\n";
        }
    }

    // Display all songs
    void displayPlaylist() const
    {
        if (songCount == 0)
        {
            cout << "\nPlaylist is empty.\n";
            return;
        }

        cout << "\n--- Playlist ---\n";
        for (int i = 0; i < songCount; i++)
        {
            cout << i + 1 << ". " << songs[i].getTitle()
                 << " (" << songs[i].getDuration() << " seconds)\n";
        }
    }

    // Calculate and display total duration in MM:SS format
    void totalDuration() const
    {
        int totalSeconds = 0;

        for (int i = 0; i < songCount; i++)
        {
            totalSeconds += songs[i].getDuration();
        }

        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;

        cout << "\nTotal Playlist Duration: "
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << endl;
    }
};

int main()
{
    Playlist playlist;

    int numberOfSongs;

    cout << "Enter the number of songs (1-10): ";
    cin >> numberOfSongs;

    while (numberOfSongs < 1 || numberOfSongs > 10)
    {
        cout << "Invalid input. Enter a number between 1 and 10: ";
        cin >> numberOfSongs;
    }

    cin.ignore();

    for (int i = 0; i < numberOfSongs; i++)
    {
        string title;
        int duration;

        cout << "\nEnter title of song " << i + 1 << ": ";
        getline(cin, title);

        cout << "Enter duration (in seconds): ";
        cin >> duration;
        cin.ignore();

        Song song(title, duration);
        playlist.addSong(song);
    }

    playlist.displayPlaylist();
    playlist.totalDuration();

    return 0;
}