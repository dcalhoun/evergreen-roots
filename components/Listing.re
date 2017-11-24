let str = ReasonReact.stringToElement;

/* type item = {
     key: string,
     listing_id: int,
     price: int,
     title: string
   }; */
let component = ReasonReact.statelessComponent("Listing");

let make = (~item, _children) => {
  ...component,
  render: (_self) =>
    <article>
      <h3> (str("item.title")) </h3>
      <h4> (str("item.price")) </h4>
    </article>
};
