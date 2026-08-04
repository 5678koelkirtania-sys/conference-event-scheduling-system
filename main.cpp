#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std; 

struct Session {
    int id;
    string title;
    int startTime; 
    int endTime;   
    string room;   

    bool operator<(const Session& other) const {
        return endTime < other.endTime;
    }
};

class ConferenceScheduler {
private:
    vector<Session> allSessions;
    vector<string> availableRooms;

public:
    ConferenceScheduler(const vector<string>& rooms) : availableRooms(rooms) {}

    void addSession(int id, const string& title, int start, int end) {
        allSessions.push_back({id, title, start, end, ""});
    }

    void scheduleEvents() {
        sort(allSessions.begin(), allSessions.end());
        vector<int> roomFreeTime(availableRooms.size(), 0);

        cout << "\n--- Conference Room Allocation & Optimization ---\n";
        for (auto& session : allSessions) {
            int bestRoomIndex = -1;
            for (size_t i = 0; i < availableRooms.size(); ++i) {
                if (roomFreeTime[i] <= session.startTime) {
                    bestRoomIndex = i;
                    break;
                }
            }

            if (bestRoomIndex != -1) {
                session.room = availableRooms[bestRoomIndex];
                roomFreeTime[bestRoomIndex] = session.endTime;
                cout << "Session " << session.id << " (\"" << session.title << "\") scheduled in " << session.room << "\n";
            } else {
                cout << "Session " << session.id << " (\"" << session.title << "\") REJECTED: Overlapping schedule.\n";
            }
        }
    }
};

int main() {
    int numRooms;
    cout << "Enter number of available conference rooms: ";
    cin >> numRooms;

    vector<string> roomNames;
    for (int i = 0; i < numRooms; ++i) {
        string rName;
        cout << "  Enter name for Room " << (i + 1) << " (e.g., Room-A): ";
        cin >> rName;
        roomNames.push_back(rName);
    }

    ConferenceScheduler scheduler(roomNames);

    int numSessions;
    cout << "\nEnter number of sessions to schedule: ";
    cin >> numSessions;

    for (int i = 0; i < numSessions; ++i) {
        int id, start, end;
        string title;
        cout << "\nSession " << (i + 1) << " Details:\n";
        cout << "  Enter Session ID: ";
        cin >> id;
        cout << "  Enter Title (use underscores instead of spaces): ";
        cin >> title;
        cout << "  Enter Start Time (e.g., 900 for 9:00 AM): ";
        cin >> start;
        cout << "  Enter End Time (e.g., 1030 for 10:30 AM): ";
        cin >> end;

        scheduler.addSession(id, title, start, end);
    }

    scheduler.scheduleEvents();
    return 0;
}
