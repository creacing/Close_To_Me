<template>
  <div id="mobileSidebar">
    <div class="links gb-animation" data-title="站点概览">
      <router-link
        class="link"
        :to="link.url"
        v-for="link of sidebar.localPath"
        :key="link"
        :class="link.name"
      >
        <i class="ic" :class="link.icon"></i>
        <!-- <span class="count">{{ sidebar.articlesNum }}</span>
        <span class="name">文章</span>-->
      </router-link>

      <a
        v-for="link of sidebar.socialLinks"
        :key="link"
        :href="link.url"
        rel="noopener external nofollow noreferrer"
        target="_blank"
        class="link"
        :class="link.name"
        :title="link.url"
      >
        <i class="ic" :class="link.icon"></i>
      </a>
    </div>
  </div>

  <!-- <div>
    <div id="mobileIndex">
      <div>
        <h2 class="title">文章目录</h2>
      </div>

      <div class="content gb-animation" data-title="文章目录">
        <ol>
          <li class="index-item" v-for="(item, index) in sideIndex" :key="item">
            <a href="#">
              <span v-html="item" class="index--title"></span>
            </a>
          </li>
        </ol>
      </div>
    </div>
  </div>-->
</template>
<script setup>
import { toRefs, defineProps } from "vue";
import config from "../../public/config";
import { RouterLink } from "vue-router";
import { store } from "@/stores/store.js";
const state = store();

const { sidebar } = config;
const { showIndex } = toRefs(state);

const props = defineProps({
  sideIndex: {
    type: Array,
    default: () => [],
  },
});

const { sideIndex } = toRefs(props);
</script>
  
<style lang='scss' scoped>
#mobileSidebar {
  position: absolute;
  top: 0;
  min-width: 15rem;
  right: 0;
  height: 100vh;
  display: flex;
  z-index: 999;
  background-color: rgba(255, 255, 255, 1);
}
[data-theme="dark"] #mobileSidebar {
  background-color: rgba(0, 0, 0, 1);
}

.links {
  display: flex;
  flex-direction: column;
  padding: 10px;
}

.links {
  text-align: center;
}

.links .link {
  display: inline-block;
  width: 1.875rem;
  height: 1.875rem;
  line-height: 1.875rem;
  text-align: center;
  position: relative;
  overflow: hidden;
  border-radius: 38%;
}

.links .link i {
  font-size: 1.4em;
  vertical-align: middle;
  transform: scale(0.8);
}

.links .link::before {
  top: 90%;
  left: -110%;
  content: "";
  width: 120%;
  height: 120%;
  position: absolute;
  transform: rotate(45deg);
}

.links .link i,
.links .link::before {
  transition: all 0.35s cubic-bezier(0.31, -0.105, 0.43, 1.59) 0s;
}

.links .link:focus::before,
.links .link:hover::before {
  top: -10%;
  left: -10%;
}

.links .link.could::before {
  background-color: var(--color-morandi-purple);
}

.links .link.could i {
  color: var(--color-morandi-purple);
}

.links .link.could1::before {
  background-color: var(--color-could1);
}

.links .link.could1 i {
  color: var(--color-could1);
}
.links .link.could2::before {
  background-color: var(--color-could2);
}

.links .link.could2 i {
  color: var(--color-could2);
}
.links .link.could3::before {
  background-color: var(--color-could3);
}

.links .link.could3 i {
  color: var(--color-could3);
}
.links .link.could4::before {
  background-color: var(--color-could4);
}

.links .link.could4 i {
  color: var(--color-could4);
}

.links .link.could5::before {
  background-color: var(--color-could5);
}

.links .link.could5 i {
  color: var(--color-could5);
}
.links .link.github::before {
  background-color: #191717;
}

.links .link.github i {
  color: #191717;
}

.links .link.twitter::before {
  background-color: #00aff0;
}

.links .link.twitter i {
  color: #00aff0;
}

.links .link.zhihu::before {
  background-color: #1e88e5;
}

.links .link.zhihu i {
  color: #1e88e5;
}

.links .link.music::before {
  background-color: #e60026;
}

.links .link.music i {
  color: #e60026;
}

.links .link.telegram::before {
  background-color: #32afed;
}

.links .link.telegram i {
  color: #32afed;
}

.links .link.about::before {
  background-color: #3b5998;
}

.links .link.about i {
  color: #3b5998;
}

.links .link:focus i,
.links .link:hover i {
  color: var(--grey-0);
  transform: scale(1);
}
</style>