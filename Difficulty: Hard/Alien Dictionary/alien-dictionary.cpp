class Solution {
	public:
	string findOrder(vector<string> &words) {
		// code here
		vector<int> present(26, 0);
		vector<int> indegree(26, 0);
		vector<int> adj[26];
		for (const string &word : words) {
			for (char c: word) {
				present[c - 'a'] = 1;
			}
		}
		int totalNodes = 0;
		for (int i = 0; i < 26; i++) {
			if (present[i]) {
				totalNodes++;
			}
		}
		int n = words.size();
		for (int i = 0; i < n - 1; i++) {
			const string &word1 = words[i];
			const string &word2 = words[i + 1];
			
			if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2) {
				return "";
			}
			int len = min(word1.size(), word2.size());
			for (int ptr = 0; ptr < len; ptr++) {
				if (word1[ptr] != word2[ptr]) {
					adj[word1[ptr]-'a'].push_back(word2[ptr]-'a');
					indegree[word2[ptr]-'a']++;
					break;
				}
			}
		}
		
		queue<int> q;
		for (int i = 0; i < 26; i++) {
			if (present[i] && indegree[i] == 0) {
				q.push(i);
			}
		}
		
		string res = "";
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			res += (char)(node + 'a');
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) {
					q.push(it);
				}
			}
		}
		if(res.size() != totalNodes){
		    return "";
		}
		
		return res;
		
	}
};
