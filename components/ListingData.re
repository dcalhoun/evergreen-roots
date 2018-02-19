[@bs.val] external host : string = "process.env.HOST";

type item = {
  listing_id: int,
  price: string,
  title: string,
  url: string
};

type items = array(item);

type storage;

let sessionStorage: storage = [%bs.raw {| window.sessionStorage |}];

[@bs.send] external setItem : (storage, string, string) => unit = "";

[@bs.send] external getItem : (storage, string) => string = "";

module Decode = {
  let item = (json) =>
    Json.Decode.{
      listing_id: json |> field("listing_id", int),
      price: json |> field("price", string),
      title: json |> field("title", string),
      url: json |> field("url", string)
    };
  let items = (items) => Json.Decode.(items |> array(item));
  let resp = (json) => Json.Decode.(json |> field("results", array(item)));
};

let serveCache = (json: Js.Json.t, callback) =>
  Js.Promise.(
    resolve(json)
    |> then_(
         (json) =>
           json
           |> Decode.resp
           |> (
             (items) => {
               callback(items);
               resolve()
             }
           )
       )
  );

let fetch = (callback) =>
  Js.Promise.(
    Fetch.fetch(host ++ "/api/listings")
    |> then_(Fetch.Response.json)
    |> then_(
         (json) => {
           setItem(sessionStorage, "listings", Json.stringify(json));
           resolve(json)
         }
       )
    |> then_(
         (json) =>
           json
           |> Decode.resp
           |> (
             (items) => {
               callback(items);
               resolve()
             }
           )
       )
    |> ignore /* TODO: Error handling */
  );

let getItems = (callback) => {
  let json = Json.parseOrRaise(getItem(sessionStorage, "listings"));
  json === {} ? true : false
};
