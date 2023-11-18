//
//  main.c
//  LAB_04
//
//  Created by Max Dokukin on 15/02/2021.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    double inpukWh;
    
    printf("Enter kWh value : ");
    
    int scanfCount = scanf("%lf", &inpukWh);
    
    if(scanfCount != 1){
        
        printf("Illegal entry\n");
        return 1;
    }
    if(inpukWh < 0){
        
        printf("Negative values are not allowed\n");
        return 1;
    }
    
    double Tier1_kWh = 0;//(up to 350)
    double Tier2_kWh = 0;// (up to 1400)
    double Tier3_kWh = 0;// (over 1400)
    
    if(inpukWh < 350){
        
        Tier1_kWh = inpukWh;
    }
    
    else if(inpukWh > 350 && inpukWh < 1450){
        
        Tier1_kWh = 350;
        Tier2_kWh = inpukWh - 350;
    }
    
    else if(inpukWh > 1450){
        
        Tier1_kWh = 350;
        Tier2_kWh = 1450 - 350;
        Tier3_kWh = inpukWh - 1450;
    }
    
    double Tier1_Bill = Tier1_kWh * 0.23;
    double Tier2_Bill = Tier2_kWh * 0.29;
    double Tier3_Bill = Tier3_kWh * 0.45;
    
    double finalBill = Tier1_Bill + Tier2_Bill + Tier3_Bill + 0.2;
    
    printf("Bill is $%.2lf\n", finalBill);
}
