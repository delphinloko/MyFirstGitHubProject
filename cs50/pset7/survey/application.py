import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    # Проверяем заполненность полей в форме, если не заполнено - выдаём соответствующую ошибку
    if not request.form.get("First_name"):
        message = "You don't enter your First name!"
        return render_template("error.html", message=message)
    elif not request.form.get("Second_name"):
        message = "You don't enter your Second name!"
        return render_template("error.html", message=message)
    elif not request.form.get("Sex"):
        message = "You don't choose your Sex!"
        return render_template("error.html", message=message)
    elif not request.form.get("email"):
        message = "You don't enter your email!"
        return render_template("error.html", message=message)
    elif not request.form.get("password"):
        message = "You don't enter your password"
        return render_template("error.html", message=message)
    elif not request.form.get("Confirm_password"):
        message = "You don't confirm your password"
        return render_template("error.html", message=message)
    elif not request.form.get("agreement"):
        message = "You don't agree with terms and conditions!"
        return render_template("error.html", message=message)
    else:
        message = ""

    # Проверяем одинаковость введённых паролей
    if request.form.get("password") != request.form.get("Confirm_password"):
        message = "You enter two different passwords!"
        return render_template("error.html", message=message)

    # Записываем в файл
    file = open("survey.csv", "a")
    writer = csv.writer(file)
    writer.writerow((request.form.get("First_name"), request.form.get("Second_name"),
    request.form.get("Sex"), request.form.get("email")))
    file.close()
    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    file = open("survey.csv", "r")
    reader = csv.reader(file)
    registered = list(reader)
    return render_template("sheet.html", users=registered)
