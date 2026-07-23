class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int totalCars = position.size();
        vector<pair<int, double>> carsData;
        for (int currentIndex = 0; currentIndex < totalCars; currentIndex++) {
            double timeToReach = (double)(target - position[currentIndex]) / speed[currentIndex];
            carsData.push_back({position[currentIndex], timeToReach});
        }
        sort(carsData.rbegin(), carsData.rend());
        int fleetCount = 0;
        double slowestTime = 0.0;
        for (int currentIndex = 0; currentIndex < totalCars; currentIndex++) {
            double currentTime = carsData[currentIndex].second; 
            if (currentTime > slowestTime) {
                slowestTime = currentTime;
                fleetCount++;
            }
        }
        return fleetCount;
    }
};