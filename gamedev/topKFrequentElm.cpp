 vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    std::vector<int> ret;
    ret.reserve(nums.size());
    for (auto n : nums) {
      if (1 == ++freq[n]) {
        ret.push_back(n);
      }
    }
    std::nth_element(ret.begin(), ret.begin() + k - 1, ret.end(), [&freq] (int l, int r) -> bool {
        return freq[l] > freq[r];
      });
    ret.resize(k);
    return ret;
  }