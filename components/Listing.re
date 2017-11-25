let str = ReasonReact.stringToElement;

type item = {
  listing_id: int,
  price: int,
  title: string
};

let component = ReasonReact.statelessComponent("Listing");

let make = (~item: item, _children) => {
  ...component,
  render: (_self) =>
    <article>
      <h3> (ReasonReact.stringToElement(item.title)) </h3>
      <h4> (ReasonReact.stringToElement(string_of_int(item.price))) </h4>
    </article>
};
