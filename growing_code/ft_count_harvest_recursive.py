def ft_recursive(days: int) -> None:
    if days == 1:
        print(f"Day {days}")
    else:
        ft_recursive(days - 1)


def ft_count_harvest_recursive() -> None:
    days = int(input("Days before harvest: "))
    ft_recursive(days)
    print("Harvest time!")
