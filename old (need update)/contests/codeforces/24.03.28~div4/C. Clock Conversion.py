def main():
    tc = int(input())

    for _ in range(tc):
        hour24 = input().split(':')
        if int(hour24[0]) >= 12:
            marker = "PM"
        else:
            marker = "AM"
        
        hour = [int(hour24[0])%12, int(hour24[1])]

        if hour[0] == 0: hour[0] = 12

        print(f"{str(hour[0]).zfill(2)}:{str(hour[1]).zfill(2)} {marker}")

    return 1


main()  # Start the program execution
