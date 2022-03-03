/* Program to implement token bus protocol */
#include <bits/stdc++.h>
#include<conio.h>
using namespace std;
int N; // # of stations
string preamble = "10010011", start = "00000001", fc = "00000000", endL = "00000010";
char data[10];

//Structure definition
struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
	int tk;
};

//function to find 1s complement
string Oc(string d) {
	
	for (int i = 0; i < d.length(); i++) {
		if (d[i] == '0')
			d[i] = '1';
		else
			d[i] = '0';
	}
	return d;
}

//function to find check sum
string checkSum(string d) {
	
	int n = d.length(), bs = 8;
	if (n % bs != 0) {
		int pad_size = bs - (n % bs);
		for (int i = 0; i < pad_size; i++) {
			d = '0' + d;
		}
	}
	
	string result = "";
	for (int i = 0; i < bs; i++) {
		result += d[i];
	}
	
	for (int i = bs; i < n; i += bs) {
		string next_block = "";
		for (int j = i; j < i + bs; j++) {
			next_block += d[j];
		}
		string add = "";
		int sum = 0, carry = 0;
		for (int k = bs - 1; k >= 0; k--) {
			sum += (next_block[k] - '0')
				+ (result[k] - '0');
			carry = sum / 2;
			if (sum == 0) {
				add = '0' + add;
				sum = carry;
			}
			else if (sum == 1) {
				add = '1' + add;
				sum = carry;
			}
			else if (sum == 2) {
				add = '0' + add;
				sum = carry;
			}
			else {
				add = '1' + add;
				sum = carry;
			}
		}
		string var = "";

		if (carry == 1) {
			for (int l = add.length() - 1; l >= 0;
				l--) {
				if (carry == 0) {
					var = add[l] + var;
				}
				else if (((add[l] - '0') + carry) % 2
						== 0) {
					var = "0" + var;
					carry = 1;
				}
				else {
					var = "1" + var;
					carry = 0;
				}
			}
			result = var;
		}
		else {
			result = add;
		}
	}
	return Oc(result);
}

//function to insert at the end
void insertEnd(struct Node** start, int value) {
	
	if (*start == NULL) {
		struct Node* new_node = new Node;
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		return;
	}

	Node *last = (*start)->prev;
	struct Node* new_node = new Node;
	new_node->data = value;
	new_node->next = *start;
	(*start)->prev = new_node;
	new_node->prev = last;
	last->next = new_node;

	new_node->tk = rand()%2;
}


//function to display the frame details
void display(struct Node* start) {
	struct Node *temp = start;

	while (temp->next != start)
	{
	    if(temp->tk==1) {
            cout << "The station " << temp->data << " is sending the frame\nFrame details: \n";
            string chcksm = checkSum(data);
            cout << preamble << "|" << start << "|" << fc << "|" << temp->next << "|" << temp << "|" << data << "|" << chcksm << "|" << endL << "\n";
		}
		temp = temp->next;
	}
}

//main function
int main() {
	
	srand(time(NULL)); //seeding time
	/* Start with the empty list */
	struct Node* st = NULL;

    cout << "Enter the number of stations : ";
    cin >> N;
	for(int i = 0; i < N; i++)
        insertEnd(&st,i);

    cout << "Enter the data : ";
    cin >> data;
	display(st);
	cout << "------------End of program------------\n";
	getch();
	return 0;
}
//end of main
