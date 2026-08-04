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
    ConferenceScheduler scheduler({"Room A", "Room B"});
    int n;
    cout << "Enter number of conference sessions: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int id, start, end;
        string title;
        cout << "Enter ID, Title, StartTime, EndTime: ";
        cin >> id >> title >> start >> end;
        scheduler.addSession(id, title, start, end);
    }
    scheduler.scheduleEvents();
    return 0;
}
