[@bs.val] external apiUrl : string = "process.env.API_URL";

[@bs.val] external port : string = "process.env.PORT";

type item = {
  listing_id: int,
  price: string,
  title: string,
  url: string,
};

type items = array(item);

module Decode = {
  let item = json =>
    Json.Decode.{
      listing_id: json |> field("listing_id", int),
      price: json |> field("price", string),
      title: json |> field("title", string),
      url: json |> field("url", string),
    };
  let items = items => Json.Decode.(items |> array(item));
  let resp = json => Json.Decode.(json |> field("results", array(item)));
};

let fetch = callback =>
  Js.Promise.(
    Fetch.fetch(apiUrl ++ ":" ++ port ++ "/api/listings")
    |> then_(Fetch.Response.json)
    |> then_(json =>
         json
         |> Decode.resp
         |> (
           items => {
             callback(items);
             resolve();
           }
         )
       )
    |> ignore
  ); /* TODO: Error handling */
