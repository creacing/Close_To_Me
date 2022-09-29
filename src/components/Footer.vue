<template>
  <div class="random--articles">
    <div class="random--content">
      <h2>随机文章</h2>
      <ul class="random--list">
        <li class="random--item" v-for="post in randomPosts">
          <div class="random--bread">
            <a href="/" :title="post.title">{{ post.title }}</a>
            <i class="random--icon ic i-angle-right"></i>
            <a href="/" :title="post.date">{{ post.date }}</a>
            <i class="random--icon ic i-angle-right"></i>
            <a href="/" :title="post.tags.join(',')">
              {{
              post.tags.join(",")
              }}
            </a>
          </div>
          <span>
            <a href="/" :title="post.description">
              {{
              post.description
              }}
            </a>
          </span>
        </li>
      </ul>
    </div>
    <NCopywrite />
  </div>
</template>
<script setup>
import NCopywrite from "@/components/Copyright.vue";
import { store } from "@/stores/store.js";
const state = store();
const posts = state.posts

// posts
const randomPosts = posts.slice(0, 10) || [];
</script>
<style lang="scss" scoped>
.random--content {
  width: 100%;
  padding: 1rem;
  .random--list {
    counter-reset: counter;
    list-style: none;
  }
  .random--item {
    padding: 0.5rem 0 0.5rem 2rem;
    border-bottom: 0.0625rem dashed var(--grey-4);
    position: relative;
  }
  .random--item::before {
    counter-increment: counter;
    content: counter(counter);
    position: absolute;
    left: 0;
    font-size: 1.5em;
    color: var(--grey-4);
    line-height: 1.2;
    text-align: right;
    width: 1em;
  }
  .random--icon {
    margin: 0 0.125rem;
    color: var(--grey-4);
  }
  .random--bread {
    display: flex;
    max-height: 1.2rem;
    text-overflow: ellipsis;
    overflow: hidden;
    white-space: nowrap;
    font-size: 0.8125em;
    align-items: center;
    flex-wrap: wrap;
  }
}
.random--articles {
  margin: 0 auto;
}
@media (min-width: 1600px) {
  .random--articles {
    width: 73%;
  }
}

@media (min-width: 1200px) {
  .random--articles {
    width: 72.5rem;
  }
}
</style>