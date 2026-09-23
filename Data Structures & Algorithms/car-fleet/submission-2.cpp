class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //lets first sort the cars by pos, and tta
        vector<pair<int, double>> cars;

        for (int i{}; i < position.size(); i++) {
            double tta = static_cast<double>(target - position[i])/speed[i];
            pair<int, double> car = {position[i], tta};
            cars.push_back(car);
        }

        //sort cars by pos asc
        sort(cars.begin(), cars.end(), [](auto a, auto b){
            return a.first < b.first;
        });

        stack<double> fleets;

        for (auto [pos, tta] : cars) {
            if (fleets.size() == 0 || fleets.top() > tta) {
                fleets.push(tta);
            } else if (tta > fleets.top()){
                while(fleets.size() != 0 && fleets.top() <= tta) {
                    fleets.pop();
                }
                fleets.push(tta);
            }
        }

        return fleets.size();
    }
};
