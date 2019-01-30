import logging as lg
from flask import Flask, request

lg.basicConfig(level=lg.DEBUG, format="%(asctime)s %(levelname)s %(name)s: %(message)s")
app = Flask(__name__)


@app.route("/")
def root():
    return "".join("<p>{}: {}</p>".format(k, v) for k, v in request.headers.items())
