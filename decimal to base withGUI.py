import tkinter as tk

def convert_number():
    nums = int(entry_dividend.get())
    base = float(entry_base.get())
    covnum = []

    process_text.delete(1.0, tk.END)  # Clear previous content

    while nums > 0:
        integer = nums // base
        left = nums % base
        nums = integer
        process_text.insert(tk.END, f"Quotient is {integer} and remainder is {left}.\n")
        covnum.append(int(left))

    covnum.reverse()
    result_label.config(text='Converted Number: ' + ''.join(map(str, covnum)))

# Create main window
root = tk.Tk()
root.title("Number Conversion")

# Set window size
root.geometry("600x400")  # Width x Height

# Dividend input
label_dividend = tk.Label(root, text="Enter the dividend:")
label_dividend.pack()
entry_dividend = tk.Entry(root)
entry_dividend.pack()

# Base input
label_base = tk.Label(root, text="Enter the base:")
label_base.pack()
entry_base = tk.Entry(root)
entry_base.pack()

# Button to perform conversion
convert_button = tk.Button(root, text="Convert", command=convert_number)
convert_button.pack()

# Process display
process_text = tk.Text(root, height=10, width=40)
process_text.pack()

# Result display
result_label = tk.Label(root, text="Converted Number:")
result_label.pack()

root.mainloop()
