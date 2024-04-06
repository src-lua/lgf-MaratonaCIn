def main():
    date = input().split('-')
    if int(date[0]) < 2023:
        print("GOOD")
    elif int(date[0]) == 2023:
        if int(date[1]) < 9:
            print("GOOD")
        elif int(date[1]) == 9:
            if int(date[2]) <= 16:
                print("GOOD")
            else:
                print("TOO LATE")
        else:
            print("TOO LATE")
    else:
        print("TOO LATE")

    return 1


main()  # Start the program execution
