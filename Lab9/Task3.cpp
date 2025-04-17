#include<iostream>
using namespace std;

class PatientRecord {
	private:
		string name;
		int id;
		string DOB, history, treatment;
	
	public:
		PatientRecord(string n, int ID, string dob, string his, string t) 
        {
			name = n;
			id = ID;
			DOB = dob;
			history = his;
			treatment = t;
		}
		void getPublicData() const 
        {
			cout << "Name = " << name << endl;
			cout << "ID = " << id << endl;
			cout << "Date of Birth = " << DOB << endl;
		}
		void getMedicalData() const 
        {
			cout << "History = " << history << endl;
			cout << "Current Treatements = " << treatment << endl;
		}
		void updateMedicalHistory(string his) 
        {
			history = his;
		}
		void addBillingDetails(const string& billingInfo) 
        {
        	treatment = billingInfo;  // assuming treatment field can hold billing info
    	}
    	
	    friend class Doctor;
	    friend class Billing;
};

class Doctor {
	PatientRecord& record;
	public:
		Doctor(PatientRecord& rec) : record(rec) {}

		void docUpdatesHistory(string his) 
        {
			record.updateMedicalHistory(his);
		}
		void viewMedicalData() const 
        {
        	record.getMedicalData();
    	}
};

class Billing {
	PatientRecord record;
	public:
		Billing(PatientRecord& rec) : record(rec) {}

	    void addBillingInfo(const string& billingInfo) 
        {
	        record.addBillingDetails(billingInfo); 
	    }
};

class Receptionist {
private:
    PatientRecord& record;

public:
    Receptionist(PatientRecord& rec) : record(rec) {}

    void viewPublicData() const 
    {
        record.getPublicData(); 
    }

};

int main() {
    PatientRecord patient("Mian Shehbaz", 12, "01/06/25", "Yaad e Mazi Azaab hai Ya Rab", "Consultation regarding current situation of country");

    Doctor doctor(patient);
    doctor.docUpdatesHistory("Patient has a new diagnosis.");
    doctor.viewMedicalData();

    Billing billing(patient);
    billing.addBillingInfo("Treatment cost: $500");

    Receptionist receptionist(patient);
    cout << "\n ---- Patient Details ----" << endl;
    receptionist.viewPublicData();

    return 0;
}
