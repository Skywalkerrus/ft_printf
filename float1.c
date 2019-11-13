/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:14:09 by bglinda           #+#    #+#             */
/*   Updated: 2019/10/21 17:14:12 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "stdlib.h"
#include <stdarg.h>

//Работа с числами в 10-ричной системе счисления
#include <stdio.h>
#define radix 10

//вывод цифры
void PrintDigit(int permissionDigit) {
    char numeralSystem[radix] = "0123456789";
    if((permissionDigit>=0)&&(permissionDigit < radix))
        printf("%c", numeralSystem[permissionDigit]);
}

//вывод числа
void PrintNumber(int *permissionNumber) {
    int i;
    for (i=9; i>=0; i--) {
        if((permissionNumber[i] >= 0) && (permissionNumber[i] < radix))
            PrintDigit(permissionNumber[i]);
    }
}

//обнуление массива
void SetToZero (int *array) {
    for (int i; i<=9; i++)
        array[i] = 0;
}

//функция умножение (первый множитель, второй множитель, результат)
void Multiplication (int *multiplier, int *multiplicand, int *result) {
    int i, j,
            carryFlag, VspRez;      //carryFlag - флаг переноса
    SetToZero (result);
    for (i = 0; i <= 9; i++) {
        carryFlag = 0;
        for (j = 0; j <= 9; j++) {
            VspRez = multiplier[i] * multiplicand[j] + carryFlag + result[i + j];
            result[i + j] = VspRez % 10;
            carryFlag = VspRez / 10;
        }
        result[i+j+1] = carryFlag;
    }
}

int main() {

    int firstNumber[60] = {3,4},  //firstNumber = A22B
            secondNumber[60] = {5,4};      //second = A
    int *firstPointer = firstNumber,
            *secondPointer = secondNumber;      //указатели

    PrintNumber(firstPointer);
    printf("\n");
    PrintNumber(secondPointer);

    printf("\n\tMultiplication\n\n");
    int multiResult[100];
    int *multiPoint = multiResult;
    Multiplication(firstPointer, secondPointer, multiPoint);
    PrintNumber(multiPoint); //вывод результата = 047BBA5433

    return 0;
}