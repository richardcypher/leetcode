//engage表示是否会与除当前的矩形之外的直线cross，但如果engage后没有cross，则不会再engage
class Solution {
public:
	bool isSelfCrossing(vector<int>& x) {
		if (x.size() < 4)
			return false;
		int len[2] = { x[0], x[1] }, direction = 0;//direction = 0 means vertical, 1 other vise.
		int i = 2;
		bool crossing = false, engage = true;
		while (i < x.size()) {
			if (len[direction] < x[i]) {
				if (crossing)
					return true;
				len[direction] = x[i];
				direction ^= 1;
				i++;
			}
			else if (len[direction] == x[i]) {
				if (i == x.size() - 1)
					return false;
				int lastlength = 0;
				if (i > 2)
					lastlength = x[i - 3];
				if (x[i + 1] + lastlength >= x[i - 1])
					return true;
				len[direction] = x[i];
				direction ^= 1;
				i++;
				len[direction] = x[i];
				direction ^= 1;
				i++;
				crossing = true;
				engage = false;
			}
			else {
				int lastlength = 0;
				crossing = true;
				if (i > 3)
					lastlength = x[i - 4];
				if (len[direction] > lastlength + x[i]) {
					len[direction] = x[i];
					direction ^= 1;
					i++;
					engage = false;
				}
				else {
					if (i == x.size() - 1)
						return false;
					int lastlength1 = 0;
					if (i > 2)
						lastlength1 = x[i - 3];
					if (i > 3 && engage && x[i + 1] + lastlength1 >= x[i - 1])
						return true;
					if (engage)
						engage = false;
					len[direction] = x[i];
					direction ^= 1;
					i++;
					len[direction] = x[i];
					direction ^= 1;
					i++;
				}
			}
		}
		return false;
	}
};
