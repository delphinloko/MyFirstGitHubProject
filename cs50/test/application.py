# export FLASK_APP=application.py
# export FLASK_DEBUG=1
# flask run

from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return "hello, world"

