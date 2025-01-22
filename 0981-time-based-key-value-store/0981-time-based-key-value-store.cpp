class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {

        // create a hashmap of key vs pair of value and timestamp
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {

        if (mp.find(key) == mp.end())
            return "";
        // vector<pair<string, int>> arr = mp[key];
        if (mp[key][0].second > timestamp)
            return "";
        int low = 0;
        int high = mp[key].size() - 1;
        int unsure = -1;
        while (low <= high) {
            int mid = low+(high-low)/2;
            if (mp[key][mid].second == timestamp) {
                return mp[key][mid].first;

            }

            else if (mp[key][mid].second < timestamp) {
                unsure = mid;
                low = mid + 1;

            } else {
                high = mid - 1;
            }
        }
        if (unsure == -1)
            return "";

        return mp[key][unsure].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */