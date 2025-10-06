# Supermarket-Bill-Maker

Electricity bill generator
Design a system to generate electricity bills based on the unit consumed by customers. The system should accept customer information including customer ID, customer name, customer telephone number, customer type (domestic/commercial) and number of units consumed. Implement functions to handle input, calculate the bill and display it in a proper format. The bill format should include all relevant details such as all information mentioned above. 

Research:
A bill is a formal document a customer receives from the vendor that states the amount that they have to pay for the goods or services purchased. A typical example can be the bills generated in hotels, grocery stores and other retail shops where the customer has to make the payment then and there. A bill can also be used to tell the amount of money a person should pay to a certain organization or how many a certain organization has to pay to the person.
A typical bill should include the sale date, seller and buyer details, description of the goods or services purchased, the total amount to be paid including the tax or fee details, payment method and warranty details if applicable.
 
References: 
Invoice vs. Bill vs. Receipt: A detailed comparison | Zoho Billing

Analyse:
Bills are used in various different situations like:
Shopping and Retail: Grocery bills, Restaurant bills, 
Household and Personal Use: Electricity, Water, Gas, Rent, Internet Bills
Subscriptions: Bills for subscriptions of apps, websites, newspapers, magazines, etc.
Healthcare: Hospital, Pharmacy, Insurance Bills
Transportation: Fuel, Taxi, Rickshaw, Bus, Vehicle Service and Maintenance Bill
Business and Professional Services: Consulting bills, Freelance work bills
Education: Tuition bills, Hostel bills, Library fines and subscription bill 

Ideate:
To design a software to generate a supermarket bill based on the types of products and quantity of products purchased. The system will accept the customer’s telephone number, the type of products and quantity of each product purchased, discount applicable if any. It’ll then calculate the total amount to be paid and display it in the following format: 
Supermarket details (name, telephone number, address, cashier number)
Bill ID
Customer Telephone number
Product name, Quantity, Total amount per product
Total Amount before discount and taxes
Discount and taxes
Total Amount to be paid

Build:

#include <stdio.h>

int main() {
	int prod_num, prod_quant, discount;
	float prod_cost = 0, total_before = 0, total_after, tax, final_total;
	long int cust_tele;
	float tax_rate = 5.0;
	int bill_id = 1001;

	printf("\n==============================================\n");
	printf("         	DMart Supermarket\n");
	printf("==============================================\n");
	printf("Address : Kothrud, Pune\n");
	printf("Tel No. : 43847 76291 | Cashier No : 7\n");
	printf("==============================================\n");

	printf("\nEnter Customer Telephone Number: ");
	scanf("%ld", &cust_tele);

	printf("\nAvailable Products:\n");
	printf("----------------------------------------------\n");
	printf(" 1. Eggs   - ₹10.00 each\n");
	printf(" 2. Bread  - ₹8.50 each\n");
	printf(" 3. Milk   - ₹25.00 each\n");
	printf(" 4. Rice   - ₹60.00 per kg\n");
	printf(" (Enter 0 to stop adding products)\n");
	printf("----------------------------------------------\n");

	printf("\n%-12s %-10s %-10s %-10s\n", "Product", "Qty", "Price", "Subtotal");
	printf("----------------------------------------------\n");

	do{
    	printf("\nEnter product number (0 to stop): ");
    	scanf("%d", &prod_num);

    	if (prod_num == 0)
        	break;

    	printf("Enter quantity: ");
    	scanf("%d", &prod_quant);

    	if (prod_num == 1) {
        	prod_cost = 10;
        	printf("%-12s %-10d %-10.2f %-10.2f\n", "Eggs", prod_quant, prod_cost, prod_cost * prod_quant);
    	} else if (prod_num == 2) {
        	prod_cost = 8.5;
        	printf("%-12s %-10d %-10.2f %-10.2f\n", "Bread", prod_quant, prod_cost, prod_cost * prod_quant);
    	} else if (prod_num == 3) {
        	prod_cost = 25;
        	printf("%-12s %d %-10.2f %-10.2f\n", "Milk", prod_quant, prod_cost, prod_cost * prod_quant);
    	} else if (prod_num == 4) {
        	prod_cost = 60;
        	printf("%-12s %-10d %-10.2f %-10.2f\n", "Rice", prod_quant, prod_cost, prod_cost * prod_quant);
    	} else {
        	printf("Invalid product number!\n");
        	continue;
    	}

    	total_before += prod_cost * prod_quant;

	} while (prod_num != 0);

	printf("----------------------------------------------\n");

	printf("\nEnter discount percentage (0 if none): ");
	scanf("%d", &discount);

	total_after = total_before - (total_before * discount / 100);
	tax = (total_after * tax_rate) / 100;
	final_total = total_after + tax;

	printf("\n\n==============================================\n");
	printf("             	CUSTOMER BILL\n");
	printf("==============================================\n");
	printf("Bill ID     	: BILL#1001");
	printf("Customer Phone  : %ld\n", cust_tele);
	printf("----------------------------------------------\n");
	printf("Total Before Discount : ₹%.2f\n", total_before);
	printf("Discount Applied (%d%%) : -₹%.2f\n", discount, (total_before * discount / 100));
	printf("Tax (%.1f%%) : +₹%.2f\n", tax_rate, tax);
	printf("----------------------------------------------\n");
	printf("TOTAL AMOUNT TO PAY : ₹%.2f\n", final_total);
	printf("==============================================\n");
	printf("      	THANK YOU FOR SHOPPING!\n");
	printf("==============================================\n\n");

	return 0;
}
Test:
==============================================
         	DMart Supermarket
==============================================
Address : Kothrud, Pune
Tel No. : 43847 76291 | Cashier No : 7
==============================================

Enter Customer Telephone Number: 6543487521

Available Products:
----------------------------------------------
 1. Eggs   - ₹10.00 each
 2. Bread  - ₹8.50 each
 3. Milk   - ₹25.00 each
 4. Rice   - ₹60.00 per kg
 (Enter 0 to stop adding products)
----------------------------------------------

Product  	Qty    	Price  	Subtotal  
----------------------------------------------

Enter product number (0 to stop): 1
Enter quantity: 3
Eggs     	3      	10.00  	30.00	 

Enter product number (0 to stop): 2
Enter quantity: 5
Bread    	5      	8.50   	42.50	 

Enter product number (0 to stop): 3
Enter quantity: 9
Milk     	9        25.00  	225.00    

Enter product number (0 to stop): 4
Enter quantity: 20
Rice     	20     	60.00  	1200.00   

Enter product number (0 to stop): 5
Enter quantity: 1
Invalid product number!

Enter product number (0 to stop): 0
----------------------------------------------

Enter discount percentage (0 if none): 17


==============================================
             	CUSTOMER BILL
==============================================
Bill ID     	: BILL#1001Customer Phone  : 6543487521
----------------------------------------------
Total Before Discount : ₹1497.50
Discount Applied (17%) : -₹254.57
Tax (5.0%) : +₹62.15
----------------------------------------------
TOTAL AMOUNT TO PAY : ₹1305.07
==============================================
      	THANK YOU FOR SHOPPING!
==============================================
