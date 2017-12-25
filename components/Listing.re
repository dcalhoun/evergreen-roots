let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Listing");

let make = (~item: ListingData.item, _children) => {
  ...component,
  render: (_self) =>
    <article>
      <h3> (str(item.title)) </h3>
      <h4> (str(item.price)) </h4>
    </article>
};
