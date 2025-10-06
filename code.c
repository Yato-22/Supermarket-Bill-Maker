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
